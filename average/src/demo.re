let average = (l: list(int)) => {
  List.(
    fold_left((+), 0, l) / length(l)
  );
};

let foo = [1, 2, 3, 4, 5];

foo |> average |> Js.log;
