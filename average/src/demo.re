let average = (l: list(int)) => {
  List.fold_left((a, b) => a + b, 0, l) / List.length(l);
};

let foo = [1, 2, 3, 4, 5];

foo |> average |> Js.log;
