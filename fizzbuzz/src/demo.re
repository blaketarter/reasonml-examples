let rec countTo = (~count as c: option(int)=?, ~l=[], s: int) => {
  switch c {
    | Some(0) => l /* Return the end result */
    | None => countTo(~count=s, ~l=[], s) /* Initialise the count variable at end */
    | Some(x) => {
      countTo(~count= x - 1, ~l=[x, ...l], s) /* Count down from the current point */
    }
  }
};

type fizz = Fizz | None;
type buzz = Buzz | None;

let isFizz = (x: int) => {
  x mod 3 === 0 ? Fizz : None
};

let isBuzz = (x: int) => {
  x mod 5 === 0 ? Buzz : None
};

let fizzBuzz = (x: int) => {
  let res = (isFizz(x), isBuzz(x));
  switch res {
  | (Fizz, Buzz) => "FizzBuzz"
  | (Fizz, _) => "Fizz"
  | (_, Buzz) => "Buzz"
  | (None, None) => string_of_int(x)
  }
};

let fizzBuzzOverList = List.map(fizzBuzz);
let logOverList = List.iter(Js.log);

countTo(100)
|> fizzBuzzOverList
|> logOverList;
