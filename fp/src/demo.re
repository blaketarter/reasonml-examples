/* let take = (numberToTake: int, data) => {
  Array.init(numberToTake, (i) => Array.get(data, i))
}; */

let take = (numberToTake: int, data) => {
  Array.sub(data, 0, numberToTake)
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> take(2)
|> Js.log; */

let skip = (numberToSkip: int, data) => {
  Array.sub(data, numberToSkip, Array.length(data) - numberToSkip)
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> skip(3)
|> Js.log; */

let tap = (effect, data) => {
  effect(data);
  data
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> tap(Js.log); */

let find = (predicate, data) => {
  let result = ref(Array.get(data, 0));
  let foundResult = ref(false);
  Array.iter((x) => {
    if (!foundResult^ && predicate(x)) {
      result := x;
      foundResult := true;
    }
  }, data);
  result^
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> find((x) => x === 2)
|> Js.log; */

let filter = (predicate, data) => {
  let filtered = ref([||]);
  Array.iter((x) => {
    if (predicate(x)) {
      filtered := Array.append(filtered^, [|x|]);
    }
  }, data);
  filtered^
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> filter((x) => x > 2)
|> Js.log; */

let reject = (predicate, data) => {
  let filtered = ref([||]);
  Array.iter((x) => {
    if (!predicate(x)) {
      filtered := Array.append(filtered^, [|x|]);
    }
  }, data);
  filtered^
};

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> reject((x) => x > 2)
|> Js.log; */

/* Bleh */
let reverse = (data) => Array.to_list(data) |> List.rev |> Array.of_list;

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> reverse
|> Js.log; */

let unique = (data) => {
  let hash = Hashtbl.create(Array.length(data));
  let uniqueArray = ref([||]);

  Array.iter((x) => {
    if (!Hashtbl.mem(hash, x)) {
      Hashtbl.add(hash, x, true);
      uniqueArray := Array.append(uniqueArray^, [|x|]);
    }
  }, data);

  Hashtbl.clear(hash);
  uniqueArray^
};

/* let foo = [|1, 2, 3, 4, 5, 5, 2|];
foo
|> unique
|> Js.log; */

let concatAll = (data) => Array.fold_left(Array.append, [||], data);

/* let foo = [|[|1, 2|], [|3, 4|], [|5|]|];
foo
|> concatAll
|> Js.log; */

let concatMap = (f) => Array.fold_left((a, b) => Array.append(a, f(b)), [||]);

/* let foo = [|1, 2, 3, 4, 5|];
foo
|> concatMap((a) => [|a, a * 10|])
|> Js.log; */

let reduce = Array.fold_left;
let reduceRight = Array.fold_right;
let map = Array.map;
let forEach = Array.iter;
