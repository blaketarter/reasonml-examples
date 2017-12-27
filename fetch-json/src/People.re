type t = {
  name: string,
  url: string,
};

let decodePerson = (json) => {
  Json.Decode.{
    url: field("url", string, json),
    name: field("name", string, json)
  }
};

let decodePeople = (json) => {
  Json.Decode.field("results", Json.Decode.array(decodePerson), json)
};

let get = () => {
  Api.get("https://swapi.co/api/people")
};
