atari <- R6::R6Class(
  "atari",
  public = list(
    ale = NULL,
    viewer = NULL,
    initialize = function(game, mode = NULL, difficulty = NULL,
                          obs_type = c("rgb", "grayscale", "ram"),
                          frameskip = 5, repeat_action_probability = 0.25,
                          full_action_space = TRUE,
                          render_mode = c("rgb_array", "human")) {

      self$ale <- ale$new()
      private$game <- game
      private$game_mode <- mode
      private$game_difficulty <- difficulty
      private$frameskip <- frameskip
      private$obs_type <- match.arg(obs_type)
      private$render_mode <- match.arg(render_mode)

      self$ale$set_float("repeat_action_probability", repeat_action_probability)

      if (private$render_mode == "human") {
        self$ale$set_bool("display_screen", TRUE)
        self$ale$set_bool("sound", TRUE)
      }

      self$seed()
    },
    seed = function(seed = NULL) {
      if (is.null(seed)) {
        seed <- sample.int(1e8, 1)
      }
      set.seed(seed)
      seed2 <- sample.int(1e8, 1)
      self$ale$set_int("random_seed", seed2)
      self$ale$load_rom(get_rom(private$game))

      if (!is.null(private$game_mode))
        self$ale$set_mode(private$game_mode)
      if (!is.null(private$game_difficulty))
        self$ale$set_difficulty(private$game_difficulty)

      list(seed, seed2)
    }
  ),
  private = list(
    game = NULL,
    game_mode = NULL,
    game_difficulty = NULL,
    frameskip = NULL,
    obs_type = NULL,
    render_mode = NULL
  )
)
