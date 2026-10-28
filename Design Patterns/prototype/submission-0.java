abstract class Shape {
    public abstract Shape clone();
    public abstract int getLength(); // Included to satisfy interface expectations if needed
}

class Rectangle extends Shape {
    private int width;
    private int height;

    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public Shape clone() {
        return new Rectangle(this.width, this.height);
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    @Override
    public int getLength() {
        return 0; // Default implementation for Shape compatibility
    }
}

class Square extends Shape {
    private int length;

    public Square(int length) {
        this.length = length;
    }

    @Override
    public Shape clone() {
        return new Square(this.length);
    }

    @Override
    public int getLength() {
        return length;
    }
}

class Test {
    public List<Shape> cloneShapes(List<Shape> shapes) {
        List<Shape> cloned = new ArrayList<>();
        for (Shape shape : shapes) {
            cloned.add(shape.clone());
        }
        return cloned;
    }
}