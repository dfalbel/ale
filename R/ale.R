ale <- R6::R6Class(
  "ale",
  public = list(
    initialize = function() {
      private$ptr = new_ale()
    },
    load_rom = function(path) {
      ale_load_rom(private$ptr, path)
      invisible(self)
    },
    set_bool = function(name, value) {
      ale_set_bool(private$ptr, name, value)
      invisible(self)
    },
    set_int = function(name, value) {
      ale_set_int(private$ptr, name, value)
      invisible(self)
    },
    set_float = function(name, value) {
      ale_set_float(private$ptr, name, value)
      invisible(self)
    },
    random_action = function() {
      ale_random_action(private$ptr)
    },
    reset_game = function() {
      ale_reset_game(private$ptr)
      invisible(self)
    },
    get_screen_rgb = function() {
      screen <- ale_get_screen_rgb(private$ptr)
      s <- array(screen, c(3, 160, 250))
      aperm(s, c(3,2,1))
    },
    get_screen_grayscale = function() {
      screen <- ale_get_screen_grayscale(private$ptr)
      matrix(screen, ncol = 160, byrow = TRUE)
    }
  ),
  private = list(
    ptr = NULL
  )
)
