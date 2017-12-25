let run1to100 = (runner) => {
  for (x in 1 to 100) {
    runner(x);
  };
};

let isFizz = (x: int) => {
  x mod 3 === 0
};

let isBuzz = (x: int) => {
  x mod 5 === 0
};

let fizzBuzz = (x: int) => {
  let remainder = (isFizz(x), isBuzz(x));
  switch remainder {
  | (true, false) => Js.log("Fizz")
  | (false, true) => Js.log("Buzz")
  | (true, true) => Js.log("FizzBuzz")
  | (false, false) => Js.log(x)
  }
};

fizzBuzz |> run1to100;
