let get = (url: string) => {
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_(resolve)
  );
};
