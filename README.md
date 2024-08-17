# ChaosRayTracing

A simple CPU path tracer created as part of the Chaos Ray Tracing course.

## Features

### BVH with Various Splitting Heuristics
- **Equal Splitting:** Simple approach dividing space into equal parts.
- **Middle Splitting:** Divides space at the midpoint of the geometry.
- **SAH (Surface Area Heuristic) Splitting:** Advanced technique that minimizes the expected cost of traversing the BVH. Although binning for faster SAH builds was considered, other features took priority.

### Cosine-Weighted Sampling for Diffuse Materials
- Efficiently simulates the reflection of light from diffuse surfaces by sampling according to a cosine distribution, which more accurately represents the physical properties of diffuse reflection.

### Uniform Light Sampling of Emissive Geometry
- Essential for rendering scenes like the classical Cornell Box, where a rectangular light source on the ceiling needs to be accurately sampled, especially at low sample counts.
- Consideration was given to implementing a power light sampler, but it was deemed unnecessary for the current scenes.

### Multiple Importance Sampling (MIS) of BSDF and Emissive Light Samples
- Combines samples from the BSDF (Bidirectional Scattering Distribution Function) and the emissive light sources to reduce variance and produce cleaner images with fewer samples.

## Usage

To run the path tracer, pass the path to a scene file (with a `.crtscene` extension) as a command line argument. Example scene files can be found in the `ChaosPathTracer/scenes` directory.
