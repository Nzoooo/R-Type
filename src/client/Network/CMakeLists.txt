set(INCROOT ${PROJECT_SOURCE_DIR}/src/client/Network/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/client/Network/)

set(SRC
    ${SRC}
    ${SRCROOT}/CustomClient.cpp
    PARENT_SCOPE
    )

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
