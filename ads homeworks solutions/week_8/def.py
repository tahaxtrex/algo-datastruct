

class TwoWayLinkedList<T> : MutableList<T> {
    private data class Node<T>(var value: T, var prev: Node<T>? = null, var next: Node<T>? = null)

    private var head: Node<T>? = null
    private var tail: Node<T>? = null
    private var _size: Int = 0

    override val size: Int
        get() = _size

    override fun isEmpty(): Boolean = _size == 0

    override fun get(index: Int): T {
        checkIndex(index)
        return getNodeAt(index).value
    }

    override fun set(index: Int, element: T): T {
        checkIndex(index)
        val node = getNodeAt(index)
        val oldValue = node.value
        node.value = element
        return oldValue
    }

    override fun add(element: T): Boolean {
        val newNode = Node(element)
        if (tail == null) {
            head = newNode
            tail = newNode
        } else {
            tail!!.next = newNode
            newNode.prev = tail
            tail = newNode
        }
        _size++
        return true
    }

    override fun add(index: Int, element: T) {
        if (index == _size) {
            add(element)
        } else {
            checkIndexForAdd(index)
            val newNode = Node(element)
            if (index == 0) {
                newNode.next = head
                head!!.prev = newNode
                head = newNode
            } else {
                val current = getNodeAt(index)
                newNode.prev = current.prev
                newNode.next = current
                current.prev!!.next = newNode
                current.prev = newNode
            }
            _size++
        }
    }


    override fun addAll(elements: Collection<T>): Boolean {
        elements.forEach { add(it) }
        return elements.isNotEmpty()
    }

    override fun addAll(index: Int, elements: Collection<T>): Boolean {
        if (index == _size) {
            return addAll(elements)
        } else {
            checkIndexForAdd(index)
            elements.forEachIndexed { i, element ->
                add(index + i, element)
            }
            return elements.isNotEmpty()
        }
    }

    override fun removeAt(index: Int): T {
        checkIndex(index)
        val node = getNodeAt(index)
        val value = node.value
        unlink(node)
        return value
    }

    override fun remove(element: T): Boolean {
        val node = findNode(element) ?: return false
        unlink(node)
        return true
    }

    override fun removeAll(elements: Collection<T>): Boolean {
        return elements.fold(false) { result, element ->
            result or remove(element)
        }
    }

    override fun retainAll(elements: Collection<T>): Boolean {
        val toRemove = this.filterNot { elements.contains(it) }
        return removeAll(toRemove)
    }

    override fun clear() {
        head = null
        tail = null
        _size = 0
    }

    override fun indexOf(element: T): Int {
        return findIndex(element, head)
    }

    override fun lastIndexOf(element: T): Int {
        return findIndex(element, tail)
    }

    override fun contains(element: T): Boolean {
        return findNode(element) != null
    }

    override fun containsAll(elements: Collection<T>): Boolean {
        return elements.all { contains(it) }
    }

    override fun iterator(): MutableIterator<T> {
        return object : MutableIterator<T> {
            private var currentNode = head
            private var lastNode: Node<T>? = null

            override fun hasNext(): Boolean = currentNode != null

            override fun next(): T {
                val value = currentNode?.value ?: throw NoSuchElementException()
                lastNode = currentNode
                currentNode = currentNode?.next
                return value
            }

            override fun remove() {
                lastNode?.let {
                    unlink(it)
                    lastNode = null
                } ?: throw IllegalStateException("No element to remove.")
            }
        }
    }

    private fun findNode(value: T): Node<T>? {
        var current = head
        while (current != null) {
            if (current.value == value) return current
            current = current.next
        }
        return null
    }

    private fun getNodeAt(index: Int): Node<T> {
        var current = if (index < _size / 2) {
            head
        } else {
            tail
        }
        val delta = if (index < _size / 2) 1 else -1
        repeat(if (index < _size / 2) index else _size - index - 1) {
            current = current!!.next ?: throw IndexOutOfBoundsException()
        }
        return current!!
    }

    private fun checkIndex(index: Int) {
        if (index < 0 || index >= _size) throw IndexOutOfBoundsException()
    }

    private fun checkIndexForAdd(index: Int) {
        if (index < 0 || index > _size) throw IndexOutOfBoundsException()
    }

    private fun unlink(node: Node<T>) {
        if (node.prev == null) {
            head = node.next
        } else {
            node.prev!!.next = node.next
        }

        if (node.next == null) {
            tail = node.prev
        } else {
            node.next!!.prev = node.prev
        }

        _size--
    }

    private fun findIndex(value: T, from: Node<T>?): Int {
        var current = from
        var index = if (from == head) 0 else _size - 1
        val delta = if (from == head) 1 else -1
        while (current != null) {
            if (current.value == value) return index
            current = if (delta > 0) current.next else current.prev
            index += delta
        }
        return -1
    }
}
