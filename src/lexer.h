#ifndef SRC_LEXER_H_
#define SRC_LEXER_H_

typedef struct lt_token_s lt_token_t;
typedef struct lt_lexer_s lt_lexer_t;

struct lt_token_s {
  char *tag;
  char *value;
};

struct lt_lexer_s {
  lt_token_t *tokens;
  char *chunk;
};

void lt_lexer_tokenize(lt_lexer_t *lexer);
void lt_lexer_clean(lt_lexer_t *lexer);
void lt_lexer_identifier(lt_lexer_t *lexer);
void lt_lexer_comment(lt_lexer_t *lexer);
void lt_lexer_whitespace(lt_lexer_t *lexer);
void lt_lexer_line(lt_lexer_t *lexer);
void lt_lexer_heredoc(lt_lexer_t *lexer);
void lt_lexer_string(lt_lexer_t *lexer);
void lt_lexer_number(lt_lexer_t *lexer);
void lt_lexer_regex(lt_lexer_t *lexer);
void lt_lexer_lua(lt_lexer_t *lexer);
void lt_lexer_literal(lt_lexer_t *lexer);

#endif /* SRC_LEXER_H_ */
