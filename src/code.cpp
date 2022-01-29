#include <Rcpp.h>
#include <ale_interface.hpp>

// [[Rcpp::export]]
int hello_world () {
  ale::ALEInterface ale;
  // Get & Set the desired settings
  ale.setInt("random_seed", 123);
  //The default is already 0.25, this is just an example
  ale.setFloat("repeat_action_probability", 0.25);
  return 1;
}



