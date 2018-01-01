type t('a) = Empty | Head('a, t('a));

let head = (ll: t('a)) => {
  switch ll {
  | Empty => None
  | Head(x, _) => Some(x)
  }
};

let rec tail = (ll: t('a)) => {
  switch ll {
  | Empty => None
  | Head(x, Empty) => Some(x)
  | Head(_, y) => tail(y)
  }
};

let prepend = (x: 'a, ll: t('a)) => Head(x, ll);

let rev = {
  let rec revAux = (l1: t('a), l2: t('a)) => {
    switch l1 {
    | Empty => l2
    | Head(a, l) => revAux(l, prepend(a, l2))
    }
  };

  (ll: t('a)) => revAux(ll, Empty)
};

let rec forEach = (f: ('a) => 'b, ll: t('a)) => {
  switch ll {
    | Empty => ()
    | Head(x, Empty) => f(x)
    | Head(x, y) => {
      f(x);
      forEach(f, y)
    }
  }
};

let rec map = (f: ('a) => 'b, l1: t('a), l2: t('a)) => {
  switch l1 {
  | Empty => l2
  | Head(x, y) => map(f, y, prepend(f(x), l2))
  }
};

let reduce = {
  let rec reduceAux = (f: ('a, 'b) => 'a, ll: t('b), x: 'a) => {
    switch ll {
    | Empty => x
    | Head(a, b) => reduceAux(f, b, f(x, a))
    }
  };

  (f: ('a, 'b) => 'a, ll: t('b), x: 'a) => reduceAux(f, ll, x)
};

let filter = {
  let rec filterAux = (f: ('a) => bool, l1: t('a), l2: t('a)) => {
    switch l1 {
    | Empty => l2
    | Head(x, y) => f(x) ? filterAux(f, y, prepend(x, l2)) : filterAux(f, y, l2)
    }
  };

  (f: ('a) => bool, ll: t('a)) => filterAux(f, ll, Empty) |> rev
};

let rec find = (f: ('a) => bool, ll: t('a)) => {
  switch ll {
  | Empty => None
  | Head(x, y) => f(x) ? Some(x) : find(f, y)
  }
};

let length = {
  let rec lengthAux = (ll: t('a), count: int) => {
    switch ll {
      | Empty => 0
      | Head(_, Empty) => count
      | Head(_, next) => lengthAux(next, count + 1)
    }
  };

  (ll: t('a)) => lengthAux(ll, 1);
};

let nth = {
  let rec nthAux = (ll: t('a), n: int, count: int) => {
    if (n === count) {
      switch ll {
      | Empty => None
      | Head(x, _) => Some(x)
      }
    } else {
      switch ll {
      | Empty => None
      | Head(_, next) => nthAux(next, n, count + 1)
      }
    }
  };

  (ll: t('a), n: int) => nthAux(ll, n, 0)
};

let fromList = {
  let rec fromListAux = (l: list('a), ll: t('a)) => {
    switch l {
    | [] => ll
    | [a, ...b] => fromListAux(b, prepend(a, ll))
    }
  };

  (l: list('a)) => fromListAux(l, Empty) |> rev
};

let fromArray = {
  let fromArrayAux = (a: array('a), ll: t('a)) => {
    switch a {
    | [||] => ll
    | _ => Array.fold_right((curr, acc) => prepend(curr, acc), a, ll)
    }
  };

  (l: array('a)) => fromArrayAux(l, Empty)
};

module Infix = {
  let (@:) = (a, b) => Head(a, b);
};
