
class Dog {
	String name, says;
}

public class Dogs {

	public static void main(String[] args) {
		Dog d1 = new Dog();
		Dog d2 = new Dog();
		d1.name = "spot";
		d1.says = "Ruff!";
		d2.name = "scruffy";
		d2.says = "Wurf!";
		System.out.println(d1.name + " says " + d1.says);
		System.out.println(d2.name + " says " + d2.says);
		System.out.println(d1.name == d2.name);
		Dog d3 = new Dog();
		d3 = d1;
		System.out.println(d3 == d1);
		System.out.println(d3.equals(d1));
		Dog d4 = new Dog();
		d4.name = d1.name;
		d4.says = d1.says;
		System.out.println(d4 == d1);
		System.out.println(d4.equals(d1));
	}

}
