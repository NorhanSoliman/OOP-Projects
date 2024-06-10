#include "FirstOccComparator.h"

bool FirstOccComparator::compare(AbstractEvent& e1, AbstractEvent& e2) const {
    return e1.getStartTime() < e2.getStartTime();
}
