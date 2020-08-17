//#include "dev.h"
#include "lib.h"
#include "recompile.h"
using namespace quanteda;

/* 
* This function recompiles tokens object.
* @used tokens_lookup()
* @creator Kohei Watanabe
* @param texts_ tokens ojbect
* @param types_ types in tokens
* @param check_gap if TRUE, remove gaps between token IDs
* @param check_dup if TRUE, merge duplicated token types into the same ID 
*/

// [[Rcpp::export]]
List qatd_cpp_tokens_recompile(const List &texts_, 
                               const CharacterVector types_,
                               const bool check_gap = true,
                               const bool check_dup = true){
    
    Texts texts = Rcpp::as<Texts>(texts_);
    Types types = Rcpp::as<Types>(types_);
    return recompile(texts, types, check_gap, check_dup);

}

/***R

#toks3 <- list(rep(0:5, 1), rep(10:15, 1))
#toks3 <- list(c(1:3, 0, 11:27))
toks3 <- list(c(1, 2, 3, 2, 4))
##unclass(qatd_cpp_tokens_recompile(toks3, c("", letters)))
#unclass(qatd_cpp_tokens_recompile(toks3, c("", "", " ", " ", letters, letters)))
unclass(qatd_cpp_tokens_recompile(toks3, c("stems", "", "stemming", "stemmed")))

#toks4 <- list(c(1:5))
#unclass(qatd_cpp_tokens_recompile(toks4, c('あ', 'い', 'う', 'え', 'お')))

*/
