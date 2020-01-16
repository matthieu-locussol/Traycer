---
layout: default
---

Traycer is a little Ray-Tracer written in C++. Ray tracing is a rendering technique for generating an image by tracing the path of light as pixels in an image plane and simulating the effects of its encounters with virtual objects.

*Project inspired by a little ray tracing project I made in C as part of my third year at [Paul Sabatier University](http://www.univ-tlse3.fr/).*

Reference : [Scratchapixel 2.0](https://www.scratchapixel.com/)

## Screenshots

![](images/PREVIEW_1.bmp)

![](images/PREVIEW_2.bmp)

![](images/PREVIEW_3.bmp)

## Features

* Supports sphere shape
* Supports Blinn-Phong Model
* Supports multiple lights : Ambient, Area, Directional, Point & Spot
* Support shadows
* Support reflections and refractions
* Support configurable FOV, camera position and view angle

## Usage

```
Traycer --help
```

## Example

Here is how to generate a scene with 1024 samples per pixel and a FOV of 30.0 for a 1920✕1080 picture :

```
Traycer -s 1024 -w 1920 -h 1080 -f 30
```