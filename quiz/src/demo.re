type quizAnswer = {
  q: string,
  a: string,
};
type answers = list(quizAnswer);
type answerFunc = (string) => quizAnswer;
type answer3 = (answerFunc, answerFunc, answerFunc);

let answer = (q: string, a: string) => {
  { q, a }
};
let ask = (q: string): answerFunc => answer(q);

let quiz3 = (q1: string, q2: string, q3: string): answer3 => (ask(q1), ask(q2), ask(q3));
let answer3 = (a1, a2, a3, q: answer3): answers => {
  let (q1, q2, q3) = q;
  [q1(a1), q2(a2), q3(a3)]
};

let bridgeKeepersQuiz = quiz3("What is your name?", "What is your quest?", "What is your favorite color?")
|> answer3("Blake", "To learn ReasonML", "Blue");

List.iter(Js.log, bridgeKeepersQuiz);
