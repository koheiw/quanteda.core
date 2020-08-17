toks <- list(1:10)
attr(toks, 'types') <- c('a', 'b', 'c') # Shorter than 10
attr(toks, 'class') <- 'tokens'
quanteda.core:::tokens_recompile(toks, 'C++')

