#include "ale_types.h"
// [[Rcpp::export]]
int hello_world () {
  ale::ALEInterface ale;
  // Get & Set the desired settings
  ale.setInt("random_seed", 123);
  //The default is already 0.25, this is just an example
  ale.setFloat("repeat_action_probability", 0.25);
  ale.setBool("display_screen", true);
  ale.setBool("sound", true);
  return 1;
}

// [[Rcpp::export]]
ale_ptr new_ale () {
  return ale_ptr(new ale::ALEInterface());
}

// [[Rcpp::export]]
void ale_set_bool (ale_ptr self, std::string name, bool value) {
  self->setBool(name, value);
}

// [[Rcpp::export]]
void ale_set_float (ale_ptr self, std::string name, float value) {
  self->setFloat(name, value);
}

// [[Rcpp::export]]
void ale_set_int (ale_ptr self, std::string name, int value) {
  self->setInt(name, value);
}

// [[Rcpp::export]]
void ale_load_rom(ale_ptr self, std::string rom) {
  self->loadROM(rom);
}

// [[Rcpp::export]]
void ale_reset_game (ale_ptr self) {
  self->reset_game();
}

// [[Rcpp::export]]
float ale_random_action (ale_ptr self) {
  ale::ActionVect legal_actions = self->getLegalActionSet();
  ale::Action a = legal_actions[rand() % legal_actions.size()];
  // Apply the action and get the resulting reward
  float reward = self->act(a);
  return reward;
}

// [[Rcpp::export]]
std::vector<std::uint8_t> ale_get_screen_rgb (ale_ptr self) {
  std::vector<std::uint8_t> buffer;
  self->getScreenRGB(buffer);
  return buffer;
}

// [[Rcpp::export]]
std::vector<std::uint8_t> ale_get_screen_grayscale (ale_ptr self) {
  std::vector<std::uint8_t> buffer;
  self->getScreenGrayscale(buffer);
  return buffer;
}
