open Webapi.Dom;

let unwrapUnsafely =
  fun
  | Some(v) => v
  | None => raise(Invalid_argument("Passed `None` to unwrapUnsafely"));

let app = document
  |> Document.getElementById("app")
  |> unwrapUnsafely;

let appendTextTo = (el, ~className="", text: string) => {
  let textNode = document
    |> Document.createElement("p");

  Element.setInnerText(textNode, text);
  Element.setClassName(textNode, className);
  Element.appendChild(textNode, el)
};

let appendTextToApp = appendTextTo(app);

module FizzBuzz {
  type f = Fizz | None;
  type b = Buzz | None;

  let isFizz = (x: int) => x mod 3 === 0 ? Fizz : None;
  let isBuzz = (x: int) => x mod 5 === 0 ? Buzz : None;

  let get = (x: int) => {
    let res = (isFizz(x), isBuzz(x));

    switch res {
    | (Fizz, Buzz) => "FizzBuzz"
    | (Fizz, _) => "Fizz"
    | (_, Buzz) => "Buzz"
    | (None, None) => string_of_int(x)
    }
  };
};

type action = Guess | NoGuess;
type answerType = Yes | No;

let yesOrNo = (a: string) => {
  switch a {
  | "yeah" => Yes
  | "yes" => Yes
  | "yea" => Yes
  | "ya" => Yes
  | "y" => Yes
  | "no" => No
  | "n" => No
  | _ => No
  }
};

let answer = try (Window.prompt("Do you want to guess the FizzBuzz?", window) |> String.lowercase |> yesOrNo) {
| _ => No
};

let state = switch answer {
| Yes => Guess
| No => NoGuess
};

let continue = ref(true);

let guessingGame = (x: int) => {
  let guess = Window.prompt("What is the result of FizzBuzz " ++ string_of_int(x), window);
  let res = FizzBuzz.get(x);
  let isCorrect = guess === res;
  switch isCorrect {
    | true => {
      Window.alert("Correct!", window);
      appendTextToApp(~className=res, res);
    }
    | false => {
      Window.alert("Incorrect!", window);
      continue := false;
    }
  }
};

for (x in 1 to 100) {
  switch (state, continue^) {
  | (Guess, true) => guessingGame(x)
  | (Guess, false) => ()
  | (NoGuess, _) => {
    let res = FizzBuzz.get(x);
    appendTextToApp(~className=res, res);
  }
  }
};
