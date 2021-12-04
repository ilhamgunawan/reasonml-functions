let discount = (~price: float, ~percent: float): float => {
  price -. (price *. (percent /. 100.0));
};
let halfOff = discount(~percent = 50.0); // halfOff is currying
let tenPercentOff = discount(~percent = 10.0); // tenPercentOff is currying
let toFixed = Js.Float.toFixedWithPrecision;
let originalPrice = 30.0;
Js.log2(
  "- Original price: $",
  toFixed(originalPrice, ~digits = 2)
);
Js.log2(
  "- Five percent off price: $",
  toFixed(discount(~price = originalPrice, ~percent = 5.0), ~digits = 2)
);
Js.log2(
  "- Half price: $",
  toFixed(halfOff(~price = originalPrice), ~digits = 2)
);
Js.log2(
  "- Ten percent off price: $",
  toFixed(tenPercentOff(~price = originalPrice), ~digits = 2)
);