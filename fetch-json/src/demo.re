let handle = (allRes: array(Js.Json.t)) => {
  switch allRes {
    | [|peopleJson, filmsJson|] => {
      let peopleRes = People.decodePeople(peopleJson);
      let filmsRes = Films.decodeFilms(filmsJson);
    
      Js.log(peopleRes);
      Js.log(filmsRes);
    }
    | _ => Js.log("No Results")
  }
};

Js.Promise.(
  all([|
    People.get(),
    Films.get(),
  |])
  |> then_(res => handle(res) |> resolve)
);
