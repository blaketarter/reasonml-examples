type comparison = Largest | Smallest;

let compare = (c: comparison, a: int, b: int) => {
  switch c {
  | Largest => (a >= b) ? a : b
  | Smallest => (a <= b) ? a : b
  }
};

let compareList = (c: comparison, l: list(int)) => {
  List.fold_left(compare(c), 0, l)
};

let foo = [1, 2, 3, 4, 5];

foo |> compareList(Largest) |> Js.log;
foo |> compareList(Smallest) |> Js.log;
