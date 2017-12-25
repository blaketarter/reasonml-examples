/* Fist implementation */
/* let sum = (l: list(int)) => {
  let total = ref(0);
  List.iter(n => total := total^ + n, l);
  total
}; */

/* Second implementation */
let sum = (l: list(int)) => {
  List.fold_left((a, b) => a + b, 0, l);
};

let foo = [1, 2, 3, 4, 5];

foo |> sum |> Js.log;
