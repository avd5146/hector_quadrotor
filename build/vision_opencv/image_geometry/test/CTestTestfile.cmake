# CMake generated Testfile for 
# Source directory: /home/ankur/hector_quadrotor_ws/src/vision_opencv/image_geometry/test
# Build directory: /home/ankur/hector_quadrotor_ws/build/vision_opencv/image_geometry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_image_geometry_nosetests_directed.py "/home/ankur/hector_quadrotor_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/ankur/hector_quadrotor_ws/build/test_results/image_geometry/nosetests-directed.py.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/ankur/hector_quadrotor_ws/build/test_results/image_geometry" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/ankur/hector_quadrotor_ws/src/vision_opencv/image_geometry/test/directed.py --with-xunit --xunit-file=/home/ankur/hector_quadrotor_ws/build/test_results/image_geometry/nosetests-directed.py.xml")
ADD_TEST(_ctest_image_geometry_gtest_image_geometry-utest "/home/ankur/hector_quadrotor_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/ankur/hector_quadrotor_ws/build/test_results/image_geometry/gtest-image_geometry-utest.xml" "--return-code" "/home/ankur/hector_quadrotor_ws/devel/lib/image_geometry/image_geometry-utest --gtest_output=xml:/home/ankur/hector_quadrotor_ws/build/test_results/image_geometry/gtest-image_geometry-utest.xml")
