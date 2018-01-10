type t = Empty | Tree(int, t, t);

let make = (x: int) => Tree(x, Empty, Empty);
let isEmpty = fun
  | Empty => true
  | _ => false
  ;
let getLeft = fun
  | Empty => None
  | Tree(_, Empty, _) => None
  | Tree(_, l, _) => Some(l)
  ;
let getRight = fun
  | Empty => None
  | Tree(_, _, Empty) => None
  | Tree(_, _, r) => Some(r)
  ;
let rec insert = (v: int, x: t) => {
  switch x {
  | Empty => make(v)
  | Tree(d, l, r) when v < d => Tree(d, insert(v, l), r)
  | Tree(d, l, r) when v > d => Tree(d, l, insert(v, r))
  | Tree(_, _, _) => x
  }
};
let rec count = (x: t) => {
  switch x {
  | Empty => 0
  | Tree(_, l, r) => 1 + count(l) + count(r)
  }
};
let rec depth = (x: t) => {
  switch x {
  | Empty => 0
  | Tree(_, l, r) => 1 + max(depth(l), depth(r))
  }
};
let rec getLargest = fun
  | Empty => None
  | Tree(d, _l, Empty) => Some(d)
  | Tree(_d, _l, r) => getLargest(r)
  ;
let rec getSmallest = fun
  | Empty => None
  | Tree(d, Empty, _r) => Some(d)
  | Tree(_d, l, _r) => getSmallest(l)
  ;
let rec contains = (v: int, x: t) => {
  switch x {
  | Empty => false
  | Tree(d, l, _r) when v < d => contains(v, l)
  | Tree(d, _l, r) when v > d => contains(v, r)
  | Tree(_d, _l, _r) => true
  }
};
let rec remove = (v: int, x: t) => {
  switch x {
  | Empty => x
  | Tree(d, Empty, r) when v === d => r
  | Tree(d, l, Empty) when v === d => l
  | Tree(d, l, r) when v === d => {
    switch (getLargest(l)) {
    | None => x
    | Some(largest) => Tree(largest, remove(largest, l), r)
    }
  }
  | Tree(d, l, r) when contains(v, x) && v < d => Tree(d, remove(v, l), r)
  | Tree(d, l, r) when contains(v, x) && v > d => Tree(d, l, remove(v, r))
  | Tree(_, _, _) => x
  }
};
let rec inOrder = (fn, x: t) => {
  switch x {
  | Empty => ()
  | Tree(d, l, r) => {
    inOrder(fn, l);
    fn(d);
    inOrder(fn, r);
  }
  }
};
let rec preOrder = (fn, x: t) => {
  switch x {
  | Empty => ()
  | Tree(d, l, r) => {
    fn(d);
    preOrder(fn, l);
    preOrder(fn, r);
  }
  }
};
let rec postOrder = (fn, x: t) => {
  switch x {
  | Empty => ()
  | Tree(d, l, r) => {
    postOrder(fn, l);
    postOrder(fn, r);
    fn(d);
  }
  }
};
let print = {
  let rec multiplyWhitespace = (w: string, c: int) => {
    switch c {
    | 0 => ""
    | _ => w ++ multiplyWhitespace(w, c - 1)
    }
  };
  let rec printAux = (x: t, depth: int) => {
    switch x {
    | Empty => ""
    | Tree(d, l, r) => {
      printAux(r, depth + 1) ++ "\n" ++ multiplyWhitespace("    ", depth) ++ string_of_int(d) ++ printAux(l, depth + 1)
    }
    }
  };

  (x: t) => printAux(x, 0)
};

let bst = make(8) |> insert(5) |> insert(4) |> insert(9) |> insert(7) |> insert(11) |> insert(1) |> insert(12) |> insert(3) |> insert(2);

Js.log("inOrder");
Js.log(bst |> inOrder(Js.log));
Js.log("preOrder");
Js.log(bst |> preOrder(Js.log));
Js.log("postOrder");
Js.log(bst |> postOrder(Js.log));
Js.log("pretty");
Js.log(bst |> print);
