import org.scalatest.FunSuite
import Example.sum

class ExampleTest extends FunSuite {

    test("sum small numbers") {
      assert(sum(1, 1) === 2)
    }

}
