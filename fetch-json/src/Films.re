type film = {
  title: string,
  url: string,
};

let decodeFilm = (json) => {
  Json.Decode.{
    url: field("url", string, json),
    title: field("title", string, json)
  }
};

let decodeFilms = (json) => {
  Json.Decode.field("results", Json.Decode.array(decodeFilm), json)
};

let get = () => {
  Api.get("https://swapi.co/api/films")
};
