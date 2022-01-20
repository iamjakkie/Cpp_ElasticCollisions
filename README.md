# Elastic collisions of multiple balls

This project aims to visualize and simulate elastic collisions of balls, which simulates a gas confined in a cylinder.

The program allows two modes:

## Standard mode

This mode uses these equations to the movement of balls and the piston:
m0*v0i + m1*v1i = m0*v0f + m1*v1f (Conservation of Linear Momentum)
Ec0i + Ec1i = Ec0f + Ec1f (Conservation of Kinetic Energy)

## Gas mode

In this mode the piston moves according to the force exerted on it by the balls

F*(tf-ti) = m0*(v0i - v0f) m0: ball mass (Linear Momentum-Impulse Theorem)
F = m1*a m1: piston mass (Newton's Second Law)

