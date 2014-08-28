{
  "targets": [{
    "target_name": "latte",
    "type": "executable",
    "dependencies": [
      "latte-lib"
    ],
    "sources": [
      "src/latte.c"
    ]
  }, {
    "target_name": "latte-lib",
    "type": "<(library)",
    "include_dirs": ["src"],
    "direct_dependent_settings": {
      "include_dirs": [ "src" ],
    },
    "sources": [
      "src/rewriter.c",
      "src/lexer.c",
      "src/parser.c",
                 
      "src/utils/fs.c",
      "src/utils/buffer.c"
    ]
  }]
}