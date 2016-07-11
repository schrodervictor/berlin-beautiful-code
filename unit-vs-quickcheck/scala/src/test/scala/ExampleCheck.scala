import org.scalacheck.Properties
import org.scalacheck.Prop.forAll

import Example.sum

object ExampleCheck extends Properties("Example") {

  property("sum") = forAll {
    (a: Int, b: Int) => sum(a, b) == a + b
  }

}
