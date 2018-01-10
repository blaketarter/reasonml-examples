// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Curry      = require("bs-platform/lib/js/curry.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

function make(x) {
  return /* Tree */[
          x,
          /* Empty */0,
          /* Empty */0
        ];
}

function isEmpty(param) {
  if (param) {
    return /* false */0;
  } else {
    return /* true */1;
  }
}

function getLeft(param) {
  if (param) {
    var l = param[1];
    if (l) {
      return /* Some */[l];
    } else {
      return /* None */0;
    }
  } else {
    return /* None */0;
  }
}

function getRight(param) {
  if (param) {
    var r = param[2];
    if (r) {
      return /* Some */[r];
    } else {
      return /* None */0;
    }
  } else {
    return /* None */0;
  }
}

function insert(v, x) {
  if (x) {
    var r = x[2];
    var l = x[1];
    var d = x[0];
    if (v < d) {
      return /* Tree */[
              d,
              insert(v, l),
              r
            ];
    } else if (v > d) {
      return /* Tree */[
              d,
              l,
              insert(v, r)
            ];
    } else {
      return x;
    }
  } else {
    return /* Tree */[
            v,
            /* Empty */0,
            /* Empty */0
          ];
  }
}

function count(x) {
  if (x) {
    return (1 + count(x[1]) | 0) + count(x[2]) | 0;
  } else {
    return 0;
  }
}

function depth(x) {
  if (x) {
    return 1 + Pervasives.max(depth(x[1]), depth(x[2])) | 0;
  } else {
    return 0;
  }
}

function getLargest(_param) {
  while(true) {
    var param = _param;
    if (param) {
      var r = param[2];
      if (r) {
        _param = r;
        continue ;
        
      } else {
        return /* Some */[param[0]];
      }
    } else {
      return /* None */0;
    }
  };
}

function getSmallest(_param) {
  while(true) {
    var param = _param;
    if (param) {
      var l = param[1];
      if (l) {
        _param = l;
        continue ;
        
      } else {
        return /* Some */[param[0]];
      }
    } else {
      return /* None */0;
    }
  };
}

function contains(v, _x) {
  while(true) {
    var x = _x;
    if (x) {
      var d = x[0];
      if (v < d) {
        _x = x[1];
        continue ;
        
      } else if (v > d) {
        _x = x[2];
        continue ;
        
      } else {
        return /* true */1;
      }
    } else {
      return /* false */0;
    }
  };
}

function remove(v, x) {
  if (x) {
    var l = x[1];
    var d = x[0];
    var exit = 0;
    if (l) {
      exit = 1;
    } else if (v === d) {
      return x[2];
    } else {
      exit = 1;
    }
    if (exit === 1) {
      var r = x[2];
      var exit$1 = 0;
      if (r) {
        exit$1 = 2;
      } else if (v === d) {
        return l;
      } else {
        exit$1 = 2;
      }
      if (exit$1 === 2) {
        if (v === d) {
          var match = getLargest(l);
          if (match) {
            var largest = match[0];
            return /* Tree */[
                    largest,
                    remove(largest, l),
                    r
                  ];
          } else {
            return x;
          }
        } else if (contains(v, x) && v < d) {
          return /* Tree */[
                  d,
                  remove(v, l),
                  r
                ];
        } else if (contains(v, x) && v > d) {
          return /* Tree */[
                  d,
                  l,
                  remove(v, r)
                ];
        } else {
          return x;
        }
      }
      
    }
    
  } else {
    return x;
  }
}

function inOrder(fn, _x) {
  while(true) {
    var x = _x;
    if (x) {
      inOrder(fn, x[1]);
      Curry._1(fn, x[0]);
      _x = x[2];
      continue ;
      
    } else {
      return /* () */0;
    }
  };
}

function preOrder(fn, _x) {
  while(true) {
    var x = _x;
    if (x) {
      Curry._1(fn, x[0]);
      preOrder(fn, x[1]);
      _x = x[2];
      continue ;
      
    } else {
      return /* () */0;
    }
  };
}

function postOrder(fn, x) {
  if (x) {
    postOrder(fn, x[1]);
    postOrder(fn, x[2]);
    return Curry._1(fn, x[0]);
  } else {
    return /* () */0;
  }
}

function multiplyWhitespace(w, c) {
  if (c !== 0) {
    return w + multiplyWhitespace(w, c - 1 | 0);
  } else {
    return "";
  }
}

function printAux(x, depth) {
  if (x) {
    return printAux(x[2], depth + 1 | 0) + ("\n" + (multiplyWhitespace("    ", depth) + (Pervasives.string_of_int(x[0]) + printAux(x[1], depth + 1 | 0))));
  } else {
    return "";
  }
}

function print(x) {
  return printAux(x, 0);
}

var bst = insert(2, insert(3, insert(12, insert(1, insert(11, insert(7, insert(9, insert(4, insert(5, /* Tree */[
                                      8,
                                      /* Empty */0,
                                      /* Empty */0
                                    ])))))))));

console.log("inOrder");

console.log(inOrder((function (prim) {
            console.log(prim);
            return /* () */0;
          }), bst));

console.log("preOrder");

console.log(preOrder((function (prim) {
            console.log(prim);
            return /* () */0;
          }), bst));

console.log("postOrder");

console.log(postOrder((function (prim) {
            console.log(prim);
            return /* () */0;
          }), bst));

console.log("pretty");

console.log(print(bst));

exports.make        = make;
exports.isEmpty     = isEmpty;
exports.getLeft     = getLeft;
exports.getRight    = getRight;
exports.insert      = insert;
exports.count       = count;
exports.depth       = depth;
exports.getLargest  = getLargest;
exports.getSmallest = getSmallest;
exports.contains    = contains;
exports.remove      = remove;
exports.inOrder     = inOrder;
exports.preOrder    = preOrder;
exports.postOrder   = postOrder;
exports.print       = print;
exports.bst         = bst;
/* bst Not a pure module */
