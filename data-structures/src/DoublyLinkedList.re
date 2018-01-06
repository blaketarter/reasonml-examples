type t('a) = Empty | Node(list('a), 'a, list('a));

let make = (x: 'a) => Node([], x, []);

let prepend = (x: 'a, y: t('a)) => {
  switch (y) {
    | Empty => make(x)
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
    | Empty => make(y)
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
    | Empty => None
    | Node(a, b, c) => {
      switch (List.rev(a)) {
        | [] => None
        | [h, ...t] => Some(Node(t, h, [b, ...c]))
      }
    }
  }
};

let next = (x: t('a)) => {
  switch x {
    | Empty => None
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
    | Empty => None
    | Node(_, b, _) => Some(b)
  }
};

let fromList = (l: list('a)) => {
  switch l {
  | [] => Empty
  | [h, ...t] => Node([], h, t)
  }
};

let fromArray = (l: array('a)) => {
  switch l {
  | [||] => Empty
  | _ => Node([], l[0], Array.sub(l, 1, Array.length(l) - 1) |> Array.to_list)
  }
};

module Maybe = {
  let curr = (x: option(t('a))) => {
    switch x {
    | None => None
    | Some(x) => curr(x)
    }
  };
};

/* let bar = make("bar");
let fooBar = prepend("foo", bar);
let fooBarBaz = append(fooBar, "baz");

Js.log(fooBarBaz);
Js.log(fooBarBaz |> curr);
Js.log(prev(fooBarBaz) |> Maybe.curr);
Js.log(next(fooBarBaz) |> Maybe.curr);

Js.log("============");

let oflist = fromList(["hello", "world"]);
let ofArray = fromArray([|"hello", "world"|]);

Js.log(oflist);
Js.log(ofArray); */
