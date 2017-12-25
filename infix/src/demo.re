let (%) = (a: int, b: int) => a mod b;

let fiveModThee = 5 % 3;
Js.log(fiveModThee);
let otherFiveModThree = 5 mod 3;
Js.log(otherFiveModThree);

let (|?) = (a, b) =>
  switch a {
  | None => b
  | _ => a
  };

let someHello = None |? None |? Some("Hello");
Js.log(someHello);
