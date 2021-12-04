let payment = (~principal: float, ~apr: float, ~years: int = 30, (): unit): float => {
  let r = (apr /. 12.0) /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  principal *. (r *. powerTerm) /. (powerTerm -. 1.0);
};
let toFixed = Js.Float.toFixedWithPrecision; // bind original function to much shorter name

let usPayment = payment(~years = 30); // usPayment should be a function
let ukPayment = payment(~years = 25); // ukPayment should be a function

Js.log("Loan of 10000 at 5%: ");
Js.log2(
  {js| - US payment: $ |js},
  toFixed(usPayment(~principal = 10000.0, ~apr = 5.0, ()), ~digits = 2)
);
Js.log2(
  {js| - UK payment: £ |js},
  toFixed(ukPayment(~principal = 10000.0, ~apr = 5.0, ()), ~digits = 2)
);