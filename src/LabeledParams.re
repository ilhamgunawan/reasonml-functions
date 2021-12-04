let payment = (~principal as p, ~apr, ~years) => {
  let r = (apr /. 12.0) /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  p *. (r *. powerTerm) /. (powerTerm -. 1.0);
};
let amount = payment(~apr=5.0, ~years=30, ~principal=10000.0);
Js.log2("Amount per month $", Js.Float.toFixedWithPrecision(amount, ~digits = 2));