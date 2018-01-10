type t('a) = Empty | Stack('a, t('a));

let make = (x: 'a) => Stack(x, Empty);

let push = (x: t('a), y: 'a) => {
  switch x {
  | Empty => make(y)
  | Stack(_, _) => Stack(y, x)
  }
};

let pop = (x: t('a)) => {
  switch x {
  | Empty => (None, Empty)
  | Stack(a, Empty) => (Some(a), Empty)
  | Stack(a, b) => (Some(a), b)
  }
};

let peek = (x: t('a)) => {
  switch x {
  | Empty => None
  | Stack(a, _) => Some(a)
  }
};

let length = {
  let rec lengthAux = (x: t('a), y: int) => {
    switch x {
    | Empty => y
    | Stack(_, b) => lengthAux(b, y + 1)
    }
  };

  (x: t('a)) => lengthAux(x, 0)
};

/* let stack0 = make("0");
let stack1 = push(stack0, "1");
let (one, stack0Again) = pop(stack1);

Js.log(stack0);
Js.log(length(stack0));
Js.log("<<<<<<<");
Js.log(stack1);
Js.log(length(stack1));
Js.log("<<<<<<<");
Js.log(one);
Js.log(stack0Again);
Js.log(length(stack0Again));
Js.log("<<<<<<<");
Js.log(peek(stack0Again));
Js.log("<<<<<<<");
Js.log(length(Empty)); */
