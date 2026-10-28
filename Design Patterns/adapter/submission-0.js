class Square {
    constructor(width) {
        this.width = width;
    }
    getWidth() {
        return this.width;
    }
}

class Circle {
    constructor(radius) {
        this.radius = radius;
    }
    getRadius() {
        return this.radius;
    }
}

class SquareHole {
    constructor(width) {
        this.width = width;
    }
    canFit(square) {
        return this.width >= square.getWidth();
    }
}

class CircleToSquareAdapter {
    constructor(circle) {
        this.circle = circle;
    }

    getWidth() {
        return this.circle.getRadius() * 2;
    }

    getSide() {
        return this.circle.getRadius() * 2;
    }
}