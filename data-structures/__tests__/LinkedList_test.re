open Jest;
open LinkedList;
open! LinkedList.Infix;

let unwrap = (x: option('a)) => {
  switch x {
    | Some(value) => value
  };
};

describe("LinkedList", () => {
  test("Infix: Makes Lists", () => ExpectJs.(expect(Js.Undefined.return(0 @: Empty)) |> toBeDefined));

  test("Head: gets first item in LinkedList", () => {
    open Expect;

    let recieved = LinkedList.head("foo" @: Empty) |> unwrap;
    let expected = "foo";

    expect(recieved) |> toBe(expected)
  });

  test("Head: returns None on empty list", () => {
    open Expect;

    let recieved = LinkedList.head(Empty);
    let expected = None;

    expect(recieved) |> toBe(expected)
  });

  test("Tail: gets last item in LinkedList", () => {
    open Expect;

    let recieved = LinkedList.tail("foo" @: "bar" @: "baz" @: Empty) |> unwrap;
    let expected = "baz";

    expect(recieved) |> toBe(expected)
  });

  test("Tail: returns None on empty list", () => {
    open Expect;

    let recieved = LinkedList.tail(Empty);
    let expected = None;

    expect(recieved) |> toBe(expected)
  });

  test("Prepend: adds item to begining of LinkedList", () => {
    open Expect;

    let recieved = LinkedList.prepend("fizz", "foo" @: "bar" @: "baz" @: Empty) |> LinkedList.head |> unwrap;
    let expected = "fizz";

    expect(recieved) |> toBe(expected)
  });

  test("Length: Gets length of LinkedList", () => {
    open Expect;

    let received = LinkedList.length("foo" @: "bar" @: "baz" @: Empty);
    let expected = 3;

    expect(received) |> toBe(expected)
  });

  test("Nth: gets item at n location", () => {
    open Expect;

    let received = LinkedList.nth("foo" @: "bar" @: "baz" @: Empty, 2) |> unwrap;
    let expected = "baz";

    expect(received) |> toBe(expected)
  });

  test("Nth: returns None on out of bounds n value", () => {
    open Expect;

    let received = LinkedList.nth("foo" @: "bar" @: "baz" @: Empty, 5);
    let expected = None;

    expect(received) |> toBe(expected)
  });

  test("Rev: reverses LinkedList items", () => {
    open Expect;

    let received = LinkedList.rev("foo" @: "bar" @: "baz" @: Empty);
    let received0 = LinkedList.nth(received, 0) |> unwrap;
    let received1 = LinkedList.nth(received, 1) |> unwrap;
    let received2 = LinkedList.nth(received, 2) |> unwrap;
    let expected0 = "baz";
    let expected1 = "bar";
    let expected2 = "foo";

    expect(received0) |> toBe(expected0);
    expect(received1) |> toBe(expected1);
    expect(received2) |> toBe(expected2);
  });
});
