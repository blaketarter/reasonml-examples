type t('a) = Empty | Tree('a, t('a), t('a));

let make = (x: 'a) => Tree(x, Empty, Empty);
let peek = (x: t('a)) => {
  switch x {
  | Empty => None
  | Tree(a, _, _) => Some(a)
  }
};
let getLeft = (x: t('a)) => {
  switch x {
  | Empty => None
  | Tree(_, l, _) => peek(l)
  }
};
let getRight = (x: t('a)) => {
  switch x {
  | Empty => None
  | Tree(_, _, r) => peek(r)
  }
};
let setLeft = (x: t('a), y: 'a) => {
  switch x {
  | Empty => make(y)
  | Tree(d, _, r) => Tree(d, make(y), r)
  }
};
let setRight = (x: t('a), y: 'a) => {
  switch x {
  | Empty => make(y)
  | Tree(d, l, _) => Tree(d, l, make(y))
  }
};

let tree = make("root");
let tree = setLeft(tree, "left");
let tree = setRight(tree, "right");

Js.log(tree);
