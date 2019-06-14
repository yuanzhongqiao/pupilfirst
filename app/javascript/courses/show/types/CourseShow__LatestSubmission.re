type t = {
  targetId: string,
  passedAt: option(string),
  evaluatorId: option(string),
};

let decode = json =>
  Json.Decode.{
    targetId: json |> field("targetId", string),
    passedAt:
      json |> field("passedAt", nullable(string)) |> Js.Null.toOption,
    evaluatorId:
      json |> field("evaluatorId", nullable(string)) |> Js.Null.toOption,
  };

let targetId = t => t.targetId;

let hasPassed = t =>
  switch (t.passedAt) {
  | Some(_time) => true
  | None => false
  };

let hasBeenEvaluated = t =>
  switch (t.evaluatorId) {
  | Some(_evaluator) => true
  | None => false
  };
