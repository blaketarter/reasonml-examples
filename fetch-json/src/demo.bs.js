// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Films$FetchJson  = require("./Films.bs.js");
var People$FetchJson = require("./People.bs.js");

function handle(allRes) {
  if (allRes.length !== 2) {
    console.log("No Results");
    return /* () */0;
  } else {
    var peopleJson = allRes[0];
    var filmsJson = allRes[1];
    var peopleRes = People$FetchJson.decodePeople(peopleJson);
    var filmsRes = Films$FetchJson.decodeFilms(filmsJson);
    console.log(peopleRes);
    console.log(filmsRes);
    return /* () */0;
  }
}

Promise.all(/* array */[
        People$FetchJson.get(/* () */0),
        Films$FetchJson.get(/* () */0)
      ]).then((function (res) {
        return Promise.resolve(handle(res));
      }));

exports.handle = handle;
/*  Not a pure module */
