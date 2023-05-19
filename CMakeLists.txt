cmake_minimum_required(VERSION 3.17)
project(SLAE)

set(CMAKE_CXX_STANDARD 17)

# Add source files for each class
set(SOURCE_FILES
        dense_matrix.cpp
        csr_matrix.cpp
        tridiagonal_matrix.cpp
        qr_decomposition.cpp
        jacobi_method.cpp
        gauss_seidel_method.cpp
        chebyshev_acceleration.cpp
        sor_method.cpp
        ssor_method.cpp
        fastest_gradient_descent.cpp
        conjugate_gradient_method.cpp
        )

# Add header files for each class
set(HEADER_FILES
        dense_matrix.h
        csr_matrix.h
        tridiagonal_matrix.h
        qr_decomposition.h
        jacobi_method.h
        gauss_seidel_method.h
        chebyshev_acceleration.h
        sor_method.h
        ssor_method.h
        fastest_gradient_descent.h
        conjugate_gradient_method.h
        )

add_library(SLAE STATIC ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(SLAE PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(Main main.cpp)
target_link_libraries(Main SLAE)

set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)