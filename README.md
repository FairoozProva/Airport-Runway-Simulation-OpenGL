# ✈️ Airport Runway Simulation with 3D Rotating Radar

A dynamic, hybrid 2D and 3D airport environment simulation built from scratch using object-oriented principles in C++ and rendered via the OpenGL and GLUT graphics libraries. This project blends detailed environmental layout modeling with a complex, multi-axis 3D rotating radar system.

<img width="1747" height="885" alt="image" src="https://github.com/user-attachments/assets/d7d4531d-f782-4b38-9231-f8184ae7ce4a" />


---

## 🚀 Features & Animations
* **Multi-Axis 3D Rotating Radar:** A standout hardware component engineered using isolated matrix transformations (`glPushMatrix`/`glPopMatrix`) and multi-dimensional rotation matrices (`glRotatef` applied to both X and Z axes) to simulate true 3D spatial rotation, depth, and perspective.
* **Automated Jet Takeoff:** Features custom vector physics translation loops mapping an aircraft's acceleration, takeoff path, and flight trajectory.
* **Drifting Cloud Layer:** Programmatic rendering of organic shapes moving dynamically across the sky canvas with an automated boundary reset loop.
* **Architectural Environment:** Rendered structural assets including a central airport terminal building with dual-panel tinted glass windows and an integrated control tower.

<img width="1235" height="624" alt="image" src="https://github.com/user-attachments/assets/1566f339-4d79-42d5-bc80-9fad6fb8c411" />
<img width="1746" height="884" alt="image" src="https://github.com/user-attachments/assets/9ae4b4d0-9090-418e-9402-0f4a5e64b28a" />


---

## 🛠️ Tools & Technologies
* **Language:** C++
* **Graphics Library:** OpenGL & GLUT (OpenGL Utility Toolkit)
* **Development Environment:** Code::Blocks
* **Operating System:** Windows

---

## 📐 OpenGL Concepts Implemented
* **Geometric Primitives:** Advanced utilization of `GL_LINES`, `GL_TRIANGLES`, `GL_QUADS`, `GL_POLYGON`, `GL_LINE_LOOP`, and `GL_TRIANGLE_FAN` to construct complex visual models.
* **Matrix Manipulations:** Hierarchical modeling using `glPushMatrix()` and `glPopMatrix()` to cleanly isolate localized animations from the global scene.
* **Spatial Transformations:** Dynamic motion mapping via `glTranslatef()` and multi-axis `glRotatef()` implementations.
* **Animation Control:** Precision callback clock pacing using `glutTimerFunc()` paired with rendering refreshes via `glutDisplayFunc()`.
* **Coordinate Mapping:** Orthographic projection setup via `glOrtho()`.
* **Performance Rendering:** Double buffering handling (`GLUT_DOUBLE`) to ensure smooth, flicker-free state changes during real-time animations.

