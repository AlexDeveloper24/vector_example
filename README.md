[![Build Status](https://travis-ci.org/)](https://travis-ci.org/)

```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
