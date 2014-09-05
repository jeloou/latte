#ifndef SRC_LEXER_H_
#define SRC_LEXER_H_

#include "utils/list.h"
#include "utils/buffer.h"

typedef struct lt_token_s lt_token_t;
typedef struct lt_lexer_s lt_lexer_t;

typedef enum {
  kTokenClass = 1,
  kTokenExtends,
  kTokenSuper,
  kTokenTrue,
  kTokenFalse,
  kTokenNull,
  kTokenThis,
  kTokenNew,
  kTokenDelete,
  kTokenTypeOf, /* 10 */
  kTokenIn,
  kTokenWhen,
  kTokenLeadingWhen,
  kTokenInstanceOf,
  kTokenNotInstanceOf,
  kTokenReturn,
  kTokenThrow,
  kTokenBreak,
  kTokenContinue,
  kTokenStatement, /* 20 */
  kTokenDebugger,
  kTokenIf,
  kTokenOwn,
  kTokenElse,
  kTokenSwitch,
  KTokenFor,
  kTokenWhile,
  kTokenDo,
  kTokenUnless,
  kTokenTry, /* 30 */
  kTokenCatch,
  kTokenFinally,
  kTokenOf,
  kTokenFor,
  kTokenForIn,  /* for v in a */
  kTokenForOf, /* for k, v of a */
  kTokenUntil,
  kTokenThen,
  kTokenLoop,
  kTokenBy, /* 40 */
  kTokenIdentifier,
  kTokenNumber,
  kTokenString,
  kTokenBool,
  kTokenRegex,
  kTokenUndefined,
  kTokenRelation,
  kTokenAssign, /* = */
  kTokenArrow, /* -> */
  kTokenFatArrow, /* => */ /* 50 */
  kTokenUnaryIncrement, /* a++ */
  kTokenUnaryDecrement, /* a-- */
  kTokenPrototype, /* a::b */
  kTokenExistentialAccessor, /* a?.b */
  kTokenPrototypeExistentialAccessor, /* a?::b */
  kTokenQuestionMark, /* ?, a? */
  kTokenLogic, /* ?, yeti ? "bear" */
  kTokenFuncExist, /* ?, fn?("hello") */
  kTokenIndexSoak, /* ?, a?[i] */
  kTokenPow, /* a ** b */ /* 60 */
  kTokenLeftParenthesis,
  kTokenParamStart,
  kTokenCallStart,
  kTokenLeftSquareBracket,
  kTokenLeftCurlyBracket,
  kTokenRightParenthesis,
  kTokenParamEnd,
  kTokenCallEnd,
  kTokenRightSquareBracket,
  kTokenRightCurlyBracket, /* 70 */
  kTokenIndent,
  kTokenOutdent,
  /* Groups of operators */
  kTokenShift,
  kTokenMath,
  kTokenUnaryMath,
  kTokenCompare,
  kTokenCompoundAssign,
  kTokenUnary,
  kTokenTerminator
} lt_token_tag_t;

struct lt_token_s {
  lt_token_tag_t tag;
  char *str;
  int num;
  int spaced;
  int new_line;
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};

struct lt_lexer_s {
  int consumed;
  int seen_for;
  int indent;
  int base_indent;
  int indebt;
  int outdebt;
  char *current;
  lt_list_t *tokens;
  lt_list_t *indents;
  lt_list_t *ends;
};

void lt_lexer_init(lt_lexer_t *lexer);
void lt_lexer_tokenize(lt_lexer_t *lexer, lt_buffer_t code[], int bufs);

#endif /* SRC_LEXER_H_ */
