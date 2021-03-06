// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var $$String                = require("bs-platform/lib/js/string.js");
var Pervasives              = require("bs-platform/lib/js/pervasives.js");
var Js_primitive            = require("bs-platform/lib/js/js_primitive.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function unwrapUnsafely(param) {
  if (param) {
    return param[0];
  } else {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "Passed `None` to unwrapUnsafely"
        ];
  }
}

var app = unwrapUnsafely(Js_primitive.null_to_opt(document.getElementById("app")));

function appendTextTo(el, $staropt$star, text) {
  var className = $staropt$star ? $staropt$star[0] : "";
  var textNode = document.createElement("p");
  textNode.innerText = text;
  textNode.className = className;
  el.appendChild(textNode);
  return /* () */0;
}

function appendTextToApp(param, param$1) {
  return appendTextTo(app, param, param$1);
}

function isFizz(x) {
  var match = +(x % 3 === 0);
  if (match !== 0) {
    return /* Fizz */0;
  } else {
    return /* None */1;
  }
}

function isBuzz(x) {
  var match = +(x % 5 === 0);
  if (match !== 0) {
    return /* Buzz */0;
  } else {
    return /* None */1;
  }
}

function get(x) {
  var res_000 = isFizz(x);
  var res_001 = isBuzz(x);
  if (res_000 !== 0) {
    if (res_001 !== 0) {
      return Pervasives.string_of_int(x);
    } else {
      return "Buzz";
    }
  } else if (res_001 !== 0) {
    return "Fizz";
  } else {
    return "FizzBuzz";
  }
}

var FizzBuzz = /* module */[
  /* isFizz */isFizz,
  /* isBuzz */isBuzz,
  /* get */get
];

function yesOrNo(a) {
  switch (a) {
    case "n" : 
    case "no" : 
        return /* No */1;
    case "y" : 
    case "ya" : 
    case "yea" : 
    case "yeah" : 
    case "yes" : 
        return /* Yes */0;
    default:
      return /* No */1;
  }
}

var answer;

try {
  answer = yesOrNo($$String.lowercase(window.prompt("Do you want to guess the FizzBuzz?")));
}
catch (exn){
  answer = /* No */1;
}

var state = answer !== 0 ? /* NoGuess */1 : /* Guess */0;

var $$continue = [/* true */1];

function guessingGame(x) {
  var guess = window.prompt("What is the result of FizzBuzz " + Pervasives.string_of_int(x));
  var res = get(x);
  var isCorrect = +(guess === res);
  if (isCorrect !== 0) {
    window.alert("Correct!");
    return appendTextToApp(/* Some */[res], res);
  } else {
    window.alert("Incorrect!");
    $$continue[0] = /* false */0;
    return /* () */0;
  }
}

for(var x = 1; x <= 100; ++x){
  var match = $$continue[0];
  if (state !== 0) {
    var res = get(x);
    appendTextToApp(/* Some */[res], res);
  } else if (match !== 0) {
    guessingGame(x);
  }
  
}

exports.unwrapUnsafely  = unwrapUnsafely;
exports.app             = app;
exports.appendTextTo    = appendTextTo;
exports.appendTextToApp = appendTextToApp;
exports.FizzBuzz        = FizzBuzz;
exports.yesOrNo         = yesOrNo;
exports.answer          = answer;
exports.state           = state;
exports.$$continue      = $$continue;
exports.guessingGame    = guessingGame;
/* app Not a pure module */
