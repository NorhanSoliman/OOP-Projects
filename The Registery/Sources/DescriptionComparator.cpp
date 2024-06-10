#include "DescriptionComparator.h"

bool DescriptionComparator::compare(AbstractEvent& e1, AbstractEvent& e2) const {
    return e1.getDescription() < e2.getDescription();
}
