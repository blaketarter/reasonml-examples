open Jest;
open LinkedList;
open! LinkedList.Infix;

let unwrap = (x: option('a)) => {
  switch x {
    | Some(value) => value
  };
};

describe("LinkedList", () => {
  test("Infix Makes Lists", () => ExpectJs.(expect(Js.Undefined.return(0 @: Empty)) |> toBeDefined));

  test("Head gets first item in LinkedList", () => {
    open Expect;

    expect(LinkedList.head("foo" @: Empty) |> unwrap) |> toBe("foo")
  });
});
