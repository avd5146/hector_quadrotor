#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/ankur/hector_quadrotor_ws/src/vision_opencv/image_geometry"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/ankur/hector_quadrotor_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/ankur/hector_quadrotor_ws/install/lib/python2.7/dist-packages:/home/ankur/hector_quadrotor_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/ankur/hector_quadrotor_ws/build" \
    "/usr/bin/python" \
    "/home/ankur/hector_quadrotor_ws/src/vision_opencv/image_geometry/setup.py" \
    build --build-base "/home/ankur/hector_quadrotor_ws/build/vision_opencv/image_geometry" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/ankur/hector_quadrotor_ws/install" --install-scripts="/home/ankur/hector_quadrotor_ws/install/bin"
