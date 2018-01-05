open Jest;
open LinkedList;
open! LinkedList.Infix;

[@bs.send] external call : ([@bs] ('a => 'b), 'c, 'a) => 'b = "";

let call = (self, arg) => call(self, (), arg);

describe("LinkedList", () => {
  test("infix: Makes Lists", () => ExpectJs.(expect(Js.Undefined.return(0 @: Empty)) |> toBeDefined));

  test("head: gets first item in LinkedList", () => {
    open Expect;

    let recieved = LinkedList.head("foo" @: Empty);
    let expected = Some("foo");

    expect(recieved) |> toEqual(expected)
  });

  test("head: returns None on empty list", () => {
    open Expect;

    let recieved = LinkedList.head(Empty);
    let expected = None;

    expect(recieved) |> toEqual(expected)
  });

  test("tail: gets last item in LinkedList", () => {
    open Expect;

    let recieved = LinkedList.tail("foo" @: "bar" @: "baz" @: Empty);
    let expected = Some("baz");

    expect(recieved) |> toEqual(expected)
  });

  test("tail: returns None on empty list", () => {
    open Expect;

    let recieved = LinkedList.tail(Empty);
    let expected = None;

    expect(recieved) |> toEqual(expected)
  });

  test("prepend: adds item to begining of LinkedList", () => {
    open Expect;

    let recieved = LinkedList.prepend("fizz", "foo" @: "bar" @: "baz" @: Empty) |> LinkedList.head;
    let expected = Some("fizz");

    expect(recieved) |> toEqual(expected)
  });

  test("length: Gets length of LinkedList", () => {
    open Expect;

    let received = LinkedList.length("foo" @: "bar" @: "baz" @: Empty);
    let expected = 3;

    expect(received) |> toEqual(expected)
  });

  test("length: Gets length of 0 on Empty LinkedList", () => {
    open Expect;

    let received = LinkedList.length(Empty);
    let expected = 0;

    expect(received) |> toEqual(expected)
  });

  test("nth: gets item at n location", () => {
    open Expect;

    let received = LinkedList.nth("foo" @: "bar" @: "baz" @: Empty, 2);
    let expected = Some("baz");

    expect(received) |> toEqual(expected)
  });

  test("nth: returns None on out of bounds n value", () => {
    open Expect;

    let received = LinkedList.nth("foo" @: "bar" @: "baz" @: Empty, 5);
    let expected = None;

    expect(received) |> toEqual(expected)
  });

  test("nth: returns None on Empty Match", () => {
    open Expect;

    let received = LinkedList.nth("foo" @: "bar" @: "baz" @: Empty, 3);
    let expected = None;

    expect(received) |> toEqual(expected)
  });

  test("rev: reverses LinkedList items", () => {
    open Expect;

    let received = LinkedList.rev("foo" @: "bar" @: "baz" @: Empty);
    let expected = "baz" @: "bar" @: "foo" @: Empty;

    expect(received) |> toEqual(expected)
  });

  test("forEach: calls the function for each item", () => {
    open ExpectJs;
    let mockFn = JestJs.inferred_fn();
    let fn = MockJs.fn(mockFn);

    let list = "foo" @: "bar" @: "baz" @: Empty;
    let _ = LinkedList.forEach((x) => {
      let _ = call(fn, x);
      ()
    }, list);
    let received = mockFn |> MockJs.calls;
    let expected = [| "foo", "bar", "baz" |];

    expect(received) |> toEqual(expected)
  });

  test("forEach: does not call the function on an empty LinkedList", () => {
    open ExpectJs;
    let mockFn = JestJs.inferred_fn();
    let fn = MockJs.fn(mockFn);

    let list = Empty;
    let _ = LinkedList.forEach((x) => {
      let _ = call(fn, x);
      ()
    }, list);
    let received = mockFn |> MockJs.calls;
    let expected = [||];

    expect(received) |> toEqual(expected)
  });

  test("map: transforms the LinkedList", () => {
    open Expect;
    
    let received = LinkedList.map((a) => a ++ "!", "foo" @: "bar" @: "baz" @: Empty);
    let expected = "foo!" @: "bar!" @: "baz!" @: Empty;

    expect(received) |> toEqual(expected)
  });

  test("reduce: reduces a LinkedList to a single value", () => {
    open Expect;

    let received = LinkedList.reduce((acc, v) => acc + v, 0 @: 1 @: 2 @: Empty, 0);
    let expected = 3;

    expect(received) |> toEqual(expected)
  });

  test("filter: filters a LinkedList to a subset of values", () => {
    open Expect;

    let received = LinkedList.filter((v) => v > 1, 0 @: 1 @: 2 @: Empty);
    let expected = 2 @: Empty;

    expect(received) |> toEqual(expected)
  });

  test("find: finds a single item that matches a condition", () => {
    open Expect;

    let received = LinkedList.find((v) => v === 1, 0 @: 1 @: 2 @: Empty);
    let expected = Some(1);

    expect(received) |> toEqual(expected)
  });

  test("find: returns none if no match is found", () => {
    open Expect;

    let received = LinkedList.find((v) => v === 3, 0 @: 1 @: 2 @: Empty);
    let expected = None;

    expect(received) |> toEqual(expected)
  });

  test("fromList: transforms a list to a linkedList", () => {
    open Expect;

    let received = LinkedList.fromList(["foo", "bar", "baz"]);
    let expected = "foo" @: "bar" @: "baz" @: Empty;

    expect(received) |> toEqual(expected)
  });

  test("fromList: transforms an empty list to an empty linkedList", () => {
    open Expect;

    let received = LinkedList.fromList([]);
    let expected = Empty;

    expect(received) |> toEqual(expected)
  });

  test("fromArray: transforms an array to a linkedList", () => {
    open Expect;

    let received = LinkedList.fromArray([|"foo", "bar", "baz"|]);
    let expected = "foo" @: "bar" @: "baz" @: Empty;

    expect(received) |> toEqual(expected)
  });

  test("fromArray: transforms an empty array to an empty linkedList", () => {
    open Expect;

    let received = LinkedList.fromArray([||]);
    let expected = Empty;

    expect(received) |> toEqual(expected)
  });
});
