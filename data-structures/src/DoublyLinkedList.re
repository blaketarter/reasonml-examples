/* https://rosettacode.org/wiki/Doubly-linked_list/Element_definition#Functional */
type t('a) = Node(list('a), 'a, list('a));

let make = (x: 'a) => Node([], x, []);

let prepend = (x: 'a, y: t('a)) => {
  switch (y) {
    | Node(a, b, c) => {
      switch a {
      | [] => Node([x], b, c)
      | _ => Node([x, ...a], b, c)
      }
    }
  }
};

let append = (x: t('a), y: 'a) => {
  switch x {
    | Node(a, b, c) => {
      switch c {
      | [] => Node(a, b, [y])
      | _ => Node(a, b, List.rev_append(c, [y]))
      }
    }
  }
};

let prev = (x: t('a)) => {
  switch x {
    | Node(a, b, c) => {
      let aRev = List.rev(a);
      switch aRev {
        | [] => None
        | [h, ...t] => Some(Node(t, h, [b, ...c]))
      }
    }
  }
};

let next = (x: t('a)) => {
  switch x {
    | Node(a, b, c) => {
      switch c {
        | [] => None
        | [h, ...t] => Some(Node(List.rev_append(a, [b]), h, t))
      }
    }
  }
};

let curr = (x: t('a)) => {
  switch x {
    | Node(_, b, _) => b
  }
};

/* forEach, map, filter, reduce, nth, fromList, fromArray */

module Maybe = {
  let curr = (x: option(t('a))) => {
    switch x {
    | None => None
    | Some(x) => Some(curr(x))
    }
  };
};

let bar = make("bar");
let fooBar = prepend("foo", bar);
let fooBarBaz = append(fooBar, "baz");
Js.log(fooBarBaz);
Js.log(fooBarBaz |> curr);
Js.log(prev(fooBarBaz) |> Maybe.curr);
Js.log(next(fooBarBaz) |> Maybe.curr);
