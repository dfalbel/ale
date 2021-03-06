// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "ale_types.h"
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// hello_world
int hello_world();
RcppExport SEXP _ale_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(hello_world());
    return rcpp_result_gen;
END_RCPP
}
// new_ale
ale_ptr new_ale();
RcppExport SEXP _ale_new_ale() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(new_ale());
    return rcpp_result_gen;
END_RCPP
}
// ale_set_bool
void ale_set_bool(ale_ptr self, std::string name, bool value);
RcppExport SEXP _ale_ale_set_bool(SEXP selfSEXP, SEXP nameSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< bool >::type value(valueSEXP);
    ale_set_bool(self, name, value);
    return R_NilValue;
END_RCPP
}
// ale_set_float
void ale_set_float(ale_ptr self, std::string name, float value);
RcppExport SEXP _ale_ale_set_float(SEXP selfSEXP, SEXP nameSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< float >::type value(valueSEXP);
    ale_set_float(self, name, value);
    return R_NilValue;
END_RCPP
}
// ale_set_int
void ale_set_int(ale_ptr self, std::string name, int value);
RcppExport SEXP _ale_ale_set_int(SEXP selfSEXP, SEXP nameSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type value(valueSEXP);
    ale_set_int(self, name, value);
    return R_NilValue;
END_RCPP
}
// ale_load_rom
void ale_load_rom(ale_ptr self, std::string rom);
RcppExport SEXP _ale_ale_load_rom(SEXP selfSEXP, SEXP romSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    Rcpp::traits::input_parameter< std::string >::type rom(romSEXP);
    ale_load_rom(self, rom);
    return R_NilValue;
END_RCPP
}
// ale_reset_game
void ale_reset_game(ale_ptr self);
RcppExport SEXP _ale_ale_reset_game(SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    ale_reset_game(self);
    return R_NilValue;
END_RCPP
}
// ale_random_action
float ale_random_action(ale_ptr self);
RcppExport SEXP _ale_ale_random_action(SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(ale_random_action(self));
    return rcpp_result_gen;
END_RCPP
}
// ale_get_screen_rgb
std::vector<std::uint8_t> ale_get_screen_rgb(ale_ptr self);
RcppExport SEXP _ale_ale_get_screen_rgb(SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(ale_get_screen_rgb(self));
    return rcpp_result_gen;
END_RCPP
}
// ale_get_screen_grayscale
std::vector<std::uint8_t> ale_get_screen_grayscale(ale_ptr self);
RcppExport SEXP _ale_ale_get_screen_grayscale(SEXP selfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< ale_ptr >::type self(selfSEXP);
    rcpp_result_gen = Rcpp::wrap(ale_get_screen_grayscale(self));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_ale_hello_world", (DL_FUNC) &_ale_hello_world, 0},
    {"_ale_new_ale", (DL_FUNC) &_ale_new_ale, 0},
    {"_ale_ale_set_bool", (DL_FUNC) &_ale_ale_set_bool, 3},
    {"_ale_ale_set_float", (DL_FUNC) &_ale_ale_set_float, 3},
    {"_ale_ale_set_int", (DL_FUNC) &_ale_ale_set_int, 3},
    {"_ale_ale_load_rom", (DL_FUNC) &_ale_ale_load_rom, 2},
    {"_ale_ale_reset_game", (DL_FUNC) &_ale_ale_reset_game, 1},
    {"_ale_ale_random_action", (DL_FUNC) &_ale_ale_random_action, 1},
    {"_ale_ale_get_screen_rgb", (DL_FUNC) &_ale_ale_get_screen_rgb, 1},
    {"_ale_ale_get_screen_grayscale", (DL_FUNC) &_ale_ale_get_screen_grayscale, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_ale(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
