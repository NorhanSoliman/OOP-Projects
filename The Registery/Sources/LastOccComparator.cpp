#include "LastOccComparator.h"

bool LastOccComparator::compare(AbstractEvent& e1, AbstractEvent& e2) const {
    return e1.lastOccurrence() < e2.lastOccurrence();
}
